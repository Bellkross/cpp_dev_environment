# This is my dev environment

## Docker

Commands to execute:

Build docker image
```
docker build -t devenv .
docker run -it --name devenv_container devenv
docker rm devenv_container
docker rmi devenv
```