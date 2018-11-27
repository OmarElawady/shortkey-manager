# Introduction:

This project si a shortkey manager for linux that associates specific words with shell commands. It runs in the background and once it detects a stored word, the command associated with it is executed.

# Installation:

Clone the repo and run `make` command in the terminal.

# How to use:

_./ash --help_ views a list of commands.

_./ash --list_:
views a list of the keys and the commands associated with each of them.

_./ash --add key command_:
Associates the key with the command.
Ex: ./ash --add hey "notify-send 'Hello world'"

_./ash --remove key_:
removes the given key.
EX: ./ash --remove hey
