# yoda

Yoda is a shell in a shell for Linux.

## Features

- Command history
- Command auto-complete
- Background processes
- Lightweight

## Build and run

You can build yoda with `make` and run it with `make run`.

The first time you try to buid the dependencies will be installed also.

Call `make help` for all the options.

## Dependencies

The dependencies are installed automatically the first time you build.

In case of a problem you can install the dependencies manually by running the following command in a terminal:

#### Debian/Ubuntu

```bash
sudo apt-get install -y make g++ libreadline6 libreadline6-dev
```

## Development

Usefull tools for development are the `make test` and `make check`.
