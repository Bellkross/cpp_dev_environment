# Use a minimal base image with a C++ compiler
FROM python:3.12-slim

# Install Git
RUN apt-get update && apt-get install -y git && \
        apt-get install -y build-essential gdb cmake && \
        apt-get install -y gcc

# Install any Python dependencies (if you have a requirements.txt)
COPY requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt

# Set the working directory to /workspace
WORKDIR /workspace

# Copy the current directory contents into the container at /app
COPY . /workspace/

# Set environment variables
ENV PYTHONUNBUFFERED 1

# CMD specifies the command to run on container startup
CMD ["/bin/bash"]