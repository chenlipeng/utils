#!/bin/bash

INDEX=10000
while (( $INDEX > 0 ))
do
	./client
	let '--INDEX'
done
