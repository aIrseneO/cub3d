#FROM alpine
#RUN apk update && apk add --no-cache build-base git libxext-dev libbsd-dev

FROM ubuntu:18.04
WORKDIR /cub3d
RUN apt-get update && apt-get install -y build-essential git libxext-dev libbsd-dev
USER 1000
CMD ["make", "-C", "/cub3d"]