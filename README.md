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

Rebuild:
```
docker rm devenv_container && docker rmi devenv && docker build -t devenv . && docker run -it --name devenv_container devenv
```

Node:

```
# installs fnm (Fast Node Manager)
curl -fsSL https://fnm.vercel.app/install | bash

# activate fnm
source ~/.bashrc

# download and install Node.js
fnm use --install-if-missing 22

# verifies the right Node.js version is in the environment
node -v # should print `v22.11.0`

# verifies the right npm version is in the environment
npm -v # should print `10.9.0`
```
