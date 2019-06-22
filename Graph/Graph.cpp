class Graph
{
	MAX_VERTS = 25
	Vertex vertexList[];
	int adjMat[][];
	int nVerts;
	StackX theStack;
}

public Graph()
{
	vertexList = new Vertex[MAX_VERTS];
	adjMat = new int[MAX_VERTS][MAX_VERTS];
	nVerts = 0;
	for(int y = 0; y < MAX_VERTS; y++)
	{
		for(int x = 0; x < MAX_VERTS; x++)
		{
			adjMat[x][y] = 0;
		}
	}
	theStack = new StackX();
}

public void addVertex(char lab)
{
	vertexList[nVerts++] = new Vertex(lab);
}

public void addEdge(int start, int end)
{
	adjMat[start][end] = 1;
	adjMat[end][start] = 1;
}

public viod displayVertex(int v)
{
	System.out.println(vertexList[v].label);
}
