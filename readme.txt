Create a repo on github
do not add a readme
In c9, highlight the folder you wish to push to github and 
right click open terminal here

Within that terminal type `git init` enter,
then `git add .` enter

Type in git commit -m "first commit" `git remote add origin` 
whatever (copy it from github page),
hit enter git push -u origin master, press enter then credentials. Done.

This way you can have several github repo’s to push and pull from all 
under one c9 project (per folder).




…or create a new repository on the command line

echo "# cs50-ide" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/Casualsunity/repositoryNames.git(e.g.:https://github.com/Casualsunity/cs50-ide.git)
git push -u origin master


…or push an existing repository from the command line

git remote add origin https://github.com/Casualsunity/cs50-ide.git
git push -u origin master


…or import code from another repository
You can initialize this repository with code from a Subversion,
Mercurial, or TFS project.