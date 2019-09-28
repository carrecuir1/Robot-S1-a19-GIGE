# Robot-S1-a19-GIGE

Ce projet a pour but de permettre à deux robots, soit un robot attaquant et un gardien de but, de faire un match entre eux. Les robots prototypes ont pour but de montrer qu'il serait possible que ceux-ci puissent aider l'entraînement de joueur de soccer.

# Git 
Pour l'utilisation de Git, vous allez avoir besoin de l'application *Git Bash*. Cette application en ligne de commande va vous permettre d'intéragir avec le projet *Robot-S1-a19-GIGE* sur le site de Github.

Si vous êtes courageux, vous pouvez essayer l'application *Git Kraken*. Cette application a une interface qui va vous permettre de faire l'interaction avec le projet git sans utiliser de console de commandes. Voici le lien : https://www.gitkraken.com/

## Quelques consignes de Git

1 - Travaillez toujours sur votre branche de développement. ##Jamais sur la branche Master
2 - Lors de vos commit, veuillez toujours mettre quelques mots expliquant ce que vous avez fait (Si possible, en anglais !). 
    Ex. : "Editing function PID increasing accuracy"
3 - Faites le plus de commit possible ! Cela va vous permettre d'avoir plusieurs lieux de sauvegarde dans le temps et retourner en arrière au besoin
4 - Assurez-vous que le code merge dans master fonctionne (au pire des cas, contacter le responsable informatique ;) )

## Installation de Git Bash

1 - Vous allez devoir installer Git via le lien suivant : https://gitforwindows.org/
2 - Executez le Git.exe
3 - Faisez suivant sans changer de réglage de l'installation (sauf si vous avez des préférences sur quelque paramètre de la console Bash)
4 - Après l'installation, vous allez poouvoir lancer le GitBash.exe

## Commandes de bases de bash

Pour voir tous les fichiers dans le repo que vous êtes situés :
*ls *

Pour changer de dossier/path : 
*cd leNomDossier* 
OU
*cd lePath*
OU
*cd ..* <------- Cela vous permet de basculer vers le dossier parent. Ex. d/patate/jambon, le dossier parent de jambon est patate

## Commandes de Git Bash

Pour allez chercher le projet qui n'est pas sur votre ordinateur, vous allez devoir faire la commande suivante :
*git clone https://github.com/carrecuir1/Robot-S1-a19-GIGE.git* 

Pour allez chercher les dernières modifications du repo(projet) en ligne :
*git pull*

Pour changer de branche :
*git checkout nomDeLaBranche*

Pour créé une nouvelle branche :
*git checkout -b nomDeLaBranche*

Pour faire un commit : 
*git add .* <-------- Cela va permettre d'indiquer quels fichiers à sauvegarder (le . signifie tous les fichiers du projet)
*git commit -m "votreMessage"* <----- Faites des messages clairs et précis 

Allez porter vos commits sur le projet en ligne : 
*git push*

Pour voir les dernières modifications faitent : 
*git status*

Voici un lien contenant d'autre commandes git utiles : https://dzone.com

/articles/top-20-git-commands-with-examples
