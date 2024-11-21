#!/bin/bash
rm -rf Snippets
mkdir Snippets

cp -r ~/.config/sublime-text/Packages/User/Snippets ./
git add .

current_datetime=$(date "+%d/%m/%y %H:%M")
git commit -m "$current_datetime"

git push origin main
