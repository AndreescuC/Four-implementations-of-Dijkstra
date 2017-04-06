build:  var1_main.c var2_main.c var3_main.c var4_main.c
	gcc var1_main.c -o Dijkstra1
	gcc var2_main.c -o Dijkstra2
	gcc var3_main.c -o Dijkstra3
	gcc var4_main.c -o Dijkstra4

run-var1:
	./Dijkstra1
run-var2:
	./Dijkstra2
run-var3:
	./Dijkstra3
run-var4:
	./Dijkstra4

clean:
	rm -f Dijkstra1
	rm -f Dijkstra2
	rm -f Dijkstra3
	rm -f Dijkstra4
