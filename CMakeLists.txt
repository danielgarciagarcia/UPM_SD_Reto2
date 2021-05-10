cmake_minimum_required(VERSION 3.19)
project(UPM_SD_Reto2 C)

set(CMAKE_C_STANDARD 99)

add_executable(cliente cliente.c servicio_xdr.c servicio_clnt.c)
add_executable(servidor servidor.c servicio_xdr.c servicio_svc.c)