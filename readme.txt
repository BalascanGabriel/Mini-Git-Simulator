Proiectul MiniGit simuleaza o varianta mai redusa a unui git.
Ideea de implementare : 
	De mentionat ca pentru lucrul cu fisiere am folosit biblioteca dirent.h ca idee obtinuta in urma cautarii pe internet . Acest header este inclus in program si in urma executiei programul ruleaza eficient.

	Fiecare parte din problema este facuta modular.

	Comentarii sunt incluse in cod unde sunt functii impumutate.

	Mentionez ca atat functii cat si idei de implementare sunt inspirate din sfantul internet . :)

1. Pentru functia INIT doar se creeaza cele 2 fisiere local si remote
2. Pentru functia ADD se ofera posibilitatea crearii fisierului local.git unde conform cerintei se adauga cele cerute
3. Functia COMMIT creaza numarul de commituri facute de utilizator conform comentariilor aplicate direct pe cod si tinand numarul de commituri facute curent . 
 
 LA RESTUL FUNCTIILOR COMENTARIILE SUNT FACUTE APROAPE INTEGRAL PE COD

4.Functia logger scrie in fisierul commands.log istoricul de comenzi