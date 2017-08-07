.name "bruce_willis"
.comment "YIPPIE KAY YAY MOTHER FUCKER"

die_hard:
	sti		r1, %:58m_pour_vivre, %1
	sti		r1, %:piege_de_cristal, %1
	sti		r1, %:une_journee_en_enfer, %1
	sti		r1, %:retour_en_enfer, %1
	sti		r1, %:belle_journee_pour_mourir, %1
	sti		r1, %:hans_gruber, %2

58m_pour_vivre:
	ld		%0, r16
	live	%999
	live	%666
	live	%999
	live	%666
	fork	%:belle_journee_pour_mourir

une_journee_en_enfer:
	live	%999
	live	%666
	live	%999
	live	%666

belle_journee_pour_mourir:
	live	%999
	live	%666
	live	%999
	live	%666
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r4,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r4,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r4,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	live	%666
	zjmp	%:58m_pour_vivre

piege_de_cristal:
	live	%999
	live	%666
	live	%999
	live	%666
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r4,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r4,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	st		r4,	-200
	st		r1,	-200
	st		r2,	-200
	st		r3,	-200
	live	%666
	ld		%0, r16
	zjmp	%:retour_en_enfer

retour_en_enfer:
	live	%999
	live	%666
	live	%999
	live	%666
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	st		r1,	-500
	live	%666

hans_gruber:
	live	%999
	live	%666
	live	%999
	live	%666
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	st		r1,	100
	live	%666
