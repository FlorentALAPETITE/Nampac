# Nampac

## Règles de la génération de map :
* taille du plateau de jeu : 31 lignes x 28 colonnes.
* le rectangle central vide doit rester identique.
* éléments de la génération :
	* p : Pacman (excatement 1)

	* R : fantôme rouge (0 à n)
	* B : fantôme bleu (0 à n)
	* P : fantôme rose (0 à n)
	* O : fantôme orange (0 à n)

	* 0 : couloir contenant un bonus Gum (bonus classique +50 points)
	* 1 : mur
	* . : couloir vide
	* + : couloir contenant un bonus SpeedPacman (accélère Pacman +100 points)
	* - : couloir contenant un bonus SlowPacman (ralenti Pacman +500 points)
	* ~ : couloir contenant un bonus SlowGhost (ralenti tous les fantômes +100 points)
	* # : couloir contenant un bonus SpeedGhost (accélère tous les fantômes +500 points)
	* $ : couloir contenant un bonus HunterBonus (permet à Pacman de manger les fantômes pendant 200 déplacements)
	* ! : couloir contenant un bonus StupidGhost (rend les fantômes stupides pendant 250 déplacements).


## Règles du jeu :
* Jeu basé sur un système risk/reward (risque/récompense).
* Pour gagner : récupérer tous les petits bonus oranges (gum).
* Toucher un fantôme entraîne la fin de la partie (sauf si le bonus Hunter est actif).
* Le joueur perd 1 point par tour de jeu.
* Ramasser une gum ajoute 50 points.
* Ramasser un bonus (SlowGhost, SpeedPacman) ajoute 100 points et facilite un peu plus le jeu.
* Ramasser un malus (SpeedGhost, SlowPacman) ajoute 500 points et complexifie un peu plus le jeu.
* Objectif : trouver la meilleure stratégie de prise de bonus pour maximiser le score.



Compilation et execution du projet :

  * Compilation et exécution :
 	$ make  

  * Exécution seule (après compilation) :
 	$ ./Nampac 


Génération de la documentation doxygen :

  * $ doxygen doxygen-config


Ouverture de la documentation HTML générée :

  * Ouvrir Documentation.html


Lien du projet sur GitHub :
  * https://github.com/FlorentALAPETITE/Nampac