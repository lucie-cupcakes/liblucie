# C Library for my projects.
Requires C99 standard.

Read the file liblucie.h for definitions and documentation about each function.

# How to use
For using it in your project, I recommend you use git submodules:

cd my_project
git init
git submodule add https://github.com/lucie-cupcakes/liblucie vendor/liblucie
git add vendor/liblucie
git commit -m "Added vendor liblucie"

You can use make -C liblucie, inside your Makefile to compile the library.
Be sure to pass your variables to have the excepted results.

I recommend enabling optimizations & linking time optimizations.

# Disclaimer
This library is mantained by my free time, and I might or not break the API.
So please be aware of it, since it's open source,
you can easily use git to roll your branch version if needed.

# Copyright
Read file LICENSE for information on copyright & distribution
Read file ATTRIBUTION.md for used/derived open source code.
