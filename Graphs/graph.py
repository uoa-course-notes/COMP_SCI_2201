from collections import namedtuple 



Graph = namedtuple("Graph", ["nodes", "edges"])


nodes = ["A", "B", "C", "D"]
edges = [
    ("A", "B"),
    ("A", "B"),
    ("A", "C"),
    ("A", "C"),
    ("A", "D"),
    ("A", "D"),
    ("B", "D"),
    ("C", "D")
]

G = Graph(nodes, edges)


def Adjacency_Dict(graph):
    """
    Returns the adjacency list representing the graph
    """
    Adj = {node:[] for node in graph.nodes}
    for edge in graph.edges:
        node1, node2 = edge[0], edge[1]
        Adj[node1].append(node2)
        Adj[node2].append(node1)
    return Adj 

