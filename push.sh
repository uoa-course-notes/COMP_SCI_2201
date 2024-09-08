#@/bin/bash 

# Check if a commit message was provided 
if [ - "$1" ]
then 
  echo "Error: No commit message provided."
  echo "Usage: ./git_push.sh \"Your commit message here"\"
  exit 1
fi 


# Add and stage all changes 
git add .


# Commit with the provided message 
git commit -m "$1"


# Push to the current branch 
git push origin Assignment_2


# Print success message 
echo "Changes have been successfully pushed to the remote repository."
