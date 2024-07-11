#!/bin/bash

cp ~/.config/sublime-text/Packages/User/*.sublime-snippet ./snippets
git add .

current_datetime=$(date "+%d/%m/%y %H:%M")
git commit -m "$current_datetime"

git push origin main
