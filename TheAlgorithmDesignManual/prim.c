#define 
#define 
#define 
#define 

typedef char direct;

typedef struct {
	int y;
	int weight;
	struct edgenode *next;
} edgenode;
typedef struct {
	edgenode *edges[MAXV+1];
	int degree[MAXV+1];
	int nvertices;
	int nedges;
	direct directed;
} graph;
prim(graph *g, int start)
{
	int i;
	edgenode *p;
	bool intree[MAXV+1];
	int distance[MAXV+1];
	int current_v;
	int candidate_v;
	int weight;
	int dist;				/* best current distance from start */

	for(i=1; i<=g->nvertices; i++) {
		intree[i] = FALSE;
		distance[i] = MAXINT;
		parent[i] = -1;
	}

	distance[start] = 0;
	v = start;
	while (intree[v] == FALSE) {
		intree[v] = TRUE;
		p = g->edges[v];
		/* scan the outgoing edges of v, update the distance from v to them */
		while (p != NULL) {
			w = p->y;
			weight = p->weight;
			if ((distance[w] > weight) && (intree[w] == FALSW)) {
				distance[w] = weight;
				parent[w] = v;
			}
			p = p->next;
		}
		v = 1;
		dist = MAXINT;
		/* scan through  all the vertices to find the one with the lowest weight 
		 * vertex and then set the new iteration with it */
		for (i=1; i<=g->nvertices; i++) {
			if ((intree[i] == FALSE) && (dist > distance[i])) {
				dist = distance[i];
				v = i;
			}
		}
	}

}
