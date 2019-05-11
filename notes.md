# Notes
## Aufgabe 3.1
**Sequentiellen Container**
- Single elements
- Sequential search (iterates through elements)
**Assoziativen Container**
- Sorted data structures (quick search)
- Variable size
- There is a Key (unmodifiable) and a Value.
- Efficient search through the key -> *O*(log N)
- The order of the elements depends on the key, and therefore independent of the order in which they are inserted.
-> Pairs: map and multimap. Simple -> set and multiset (key and value are identic and unique)


**Speichern der Punkte eines Polygons**
Secuential container -> The points will probably need to be visited sequentially. A vector would allow to increase the number of points, is efficient with LIFO-Semantik. Also a list could be used (efficiency?)
```
// Point is a struct with int x, y;
vector<Point> polygon;
```
**Zuordnung von Farbnamen und entsprechenden RGB-Werten**
Since there is a name and a type (a struct for color) pair, a map could be used. Each name is also unique.
```
Color is a struct with int r, g, b;
map<string, Color> palette;
// E.g.

palette["Red"s] = Color{255, 0, 0};
```
**FIFO-Warteschlange von Druckaufträgen**
A queue (an adaptor for deque).
```
...
queue <Printjob> print_queue;

print_queue.push(job_1);  
print_queue.push(job_2);  
print_queue.push(job_3);  
 
print(print_queue.front()); // returns the front element - job_1
print_queue.pop(); // removes the front element from the queue - job_1

```