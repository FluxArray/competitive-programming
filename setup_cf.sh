#!/bin/bash

# usage: cf id
contest_id=$1

if [ -z "$contest_id" ]; then
    echo "Usage: cf <contest_id>"
    exit 1
fi

# Fetch contest info
info=$(curl -s "https://codeforces.com/api/contest.standings?contestId=$contest_id&from=1&count=1")

if [ "$(echo "$info" | jq -r .status)" != "OK" ]; then
    echo "Invalid contest ID or contest not started."
    exit 1
fi

# Contest name
contest_name=$(echo "$info" | jq -r '.result.contest.name')

# Base directory where all contests are stored
base="$HOME/Documents/cpps/cp/cf"

# Final folder path
folder="$base/$(echo "$contest_name" | tr ' ' '_' | tr -cd '[:alnum:]_')"
mkdir -p "$folder"

# Fetch problems
problems_info=$(curl -s "https://codeforces.com/api/contest.standings?contestId=$contest_id&from=1&count=100")
problems=$(echo "$problems_info" | jq -r '.result.problems[].index')

# Template file location
template="$HOME/Documents/cpps/cp/cf/cp_template.cpp"

# Create files
for p in $problems; do
    cp "$template" "$folder/${p}.cpp"
    touch "$folder/${p}.in"
done

#Open all generated files in Sublime Text
open -a "Sublime Text" "$folder"/*.cpp
