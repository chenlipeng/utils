typedef struct zskiplistNode {
	char *obj;
	double score;
	struct zskiplistLevel {
		struct zskiplistNode *forward;
		unsigned int span;
	} level[];
} zskiplistNode;

typedef struct zskiplist {
	zskiplistNode *header, *tai;
	unsigned long length;
	int level;
} zskiplist;
