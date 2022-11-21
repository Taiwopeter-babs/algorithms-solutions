#!/bin/bash

echo "Enter file to add:"
read file_name

git add $file_name

echo "Enter commit message:"
read commit_message

git commit -m "$commit_message"

echo "Enter name of branch:"
read branch_name

git push origin $branch_name

read
