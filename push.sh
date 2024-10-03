#&/bin/bash 


# Checks if a commit message was provided
if [ - "$1"]
then
	echo "Error: No commit message provided."
	echo "Usage: ./push.sh \"Your commit message here.\""
	exit 1 
fi 




# Add and stage all changes at once 
git add .


# Commit with the provided message 
git commit -m "$1"


# Push to the current branch 
git push origin Assignment_3


# Print success message 
echo "Changes have been successfully pushed to the remote repository."

