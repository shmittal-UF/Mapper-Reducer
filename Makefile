default: combiner reducer mapper

combiner:
	gcc -o combiner Combiner.c
reducer:
	gcc -o reducer Reducer.c
mapper:
	gcc -o mapper Mapper.c
