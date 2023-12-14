# Use the official Python image with version 3.11
FROM python:3.11

# Install Git
RUN apt-get update && apt-get install -y git

# Set the working directory to /workspace
WORKDIR /workspace

# Copy the current directory contents into the container at /app
COPY . /workspace/

# Set environment variables
ENV PYTHONUNBUFFERED 1

# CMD specifies the command to run on container startup
CMD ["/bin/bash"]