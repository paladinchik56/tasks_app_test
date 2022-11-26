FROM ubuntu:22.04

COPY . /app

RUN apt update && apt upgrade -y -y

RUN apt install make -y && apt install cmake -y

RUN apt install g++ -y

RUN cd app/ && cmake CMakeLists.txt && make
RUN ls

CMD ["app/tasks_app"]