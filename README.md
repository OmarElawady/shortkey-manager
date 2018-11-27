# Introduction:

This project si a shortkey manager for linux that associates specific words with shell commands. It runs in the background and once it detects a stored word, the command associated with it is executed.

# Installation:

Clone the repo and run `make` command in the terminal.

# How to use:

./ash --help views a list of commands.

./ash --list:
views a list of the keys and the commands associated with each of them.

./ash --add key command:
Associates the key with the command.
Ex: ./ash --add hey "notify-send 'Hello world'"

./ash --remove key:
removes the given key.

