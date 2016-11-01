# Nampac

Règles de la génération de map :
	- taille du plateau de jeu : 31 lignes x 28 colonnes
	- éléments de la génération :
		- p : Pacman (excatement 1)
		- R : fantôme rouge (0 à n)
		- B : fantôme bleu (0 à n)
		- P : fantôme rose (0 à n)
		- O : fantôme orange (0 à n)

		- 0 : couloir contenant un bonus Gum (bonus classique)
		- 1 : mur
		- . : couloir vide
		- + : couloir contenant un bonus SpeedPacman (accélère Pacman)
		- - : couloir contenant un bonus SlowPacman (ralenti Pacman)
		- ~ : couloir contenant un bonus SlowGhost (ralenti tous les fantômes)
		- # : couloir contenant un bonus SpeedGhost (accélère tous les fantômes)