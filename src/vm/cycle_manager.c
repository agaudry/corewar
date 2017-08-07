/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaudry <agaudry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:15:00 by agaudry           #+#    #+#             */
/*   Updated: 2017/07/30 12:34:27 by agaudry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

void	process_manager(t_env *env)
{
	t_list		*tmp;
	t_process	*p;

	tmp = env->process;
	while (tmp)
	{
		p = ((t_process *)(tmp->content));
		if (p->pc >= MEM_SIZE)
			p->pc %= MEM_SIZE;
		while (p->pc < 0)
			p->pc += MEM_SIZE;
		if (!p->ft)
			assign_task(env->field[p->pc % MEM_SIZE], env, p);
		else
		{
			if (p->countdown == 1)
			{
				p->pc = (p->pc + p->ft(env, p)) % MEM_SIZE;
				p->ft = NULL;
			}
			p->countdown -= 1;
		}
		p->last_live += 1;
		tmp = tmp->next;
	}
}

void	round_manager(t_env *env, int round_size)
{
	t_list	*tmp;

	while (round_size > 0)
	{
		tmp = env->process;
		if (env->dump >= 0 && env->cycle_counter == env->dump)
		{
			print_field(env->field);
			exit(EXIT_SUCCESS);
		}
		if (env->step && (env->cycle_counter % env->step) == 0)
		{
			print_field(env->field);
			read(0, NULL, 1);
		}
		env->cycle_counter++;
		if (env->verb & CYCLES)
			ft_printf("It is now cycle %d\n", env->cycle_counter);
		process_manager(env);
		round_size--;
	}
}

void	check_lives(t_env *env, t_list *process)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	current = process;
	next = current->next;
	while (current)
	{
		if (get_p(current)->last_live >= env->cycle_to_die)
		{
			kill_process(env, prev, current);
			if (prev)
				prev->next = next;
		}
		else
		{
			reset_p_live(current);
			prev = current;
		}
		current = next;
		if (current)
			next = current->next;
	}
}

void	cycle_manager(t_env *env)
{
	int			checks;
	static int	q;

	env->cycle_to_die = CYCLE_TO_DIE;
	checks = 0;
	while (env->process)
	{
		if (env->cycle_to_die < 0 && q == 0)
		{
			q = 1;
			round_manager(env, 1);
		}
		round_manager(env, env->cycle_to_die);
		check_lives(env, env->process);
		checks++;
		if (checks == MAX_CHECKS || env->live_nb >= NBR_LIVE)
		{
			env->cycle_to_die -= CYCLE_DELTA;
			if (env->verb & CYCLES)
				ft_printf("Cycle to die is now %d\n", env->cycle_to_die);
			checks = 0;
		}
		env->live_nb = 0;
	}
}
