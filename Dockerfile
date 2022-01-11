FROM ubuntu:18.04
#FROM alpine

RUN apt-get update && apt-get install -y build-essential git libxext-dev libbsd-dev
#RUN apk update && apk add --no-cache build-base git libxext-dev libbsd-dev

#COPY . /cub3d
#WORKDIR /cub3d

CMD ["make", "-C", "/cub3d"]
