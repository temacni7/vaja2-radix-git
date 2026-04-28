FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++

WORKDIR /app

COPY . .

RUN g++ -o vaja2 main.cpp radix.cpp

CMD ["./vaja2"]
