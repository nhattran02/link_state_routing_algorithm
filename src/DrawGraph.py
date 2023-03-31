# DrawGraph.py 
# Created on: 30.3.2023
# nhat.tranminh

import sys
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

def drawGraph(pyMatrix):
    adj_matrix = np.array(pyMatrix)

    # Create a new graph
    G = nx.Graph()

    # Add nodes to the graph
    for i in range(len(adj_matrix)):
        G.add_node(chr(i+65))

    # Add edges to the graph
    for i in range(len(adj_matrix)):
        for j in range(i + 1, len(adj_matrix)):
            if adj_matrix[i][j] > 0:
                G.add_edge(chr(i+65), chr(j+65), weight=adj_matrix[i][j])

    # Draw the graph
    pos = nx.spring_layout(G)
    nx.draw(G, pos, with_labels=True, node_color = 'red', node_size = 800)
    labels = nx.get_edge_attributes(G, "weight")
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_color='blue', font_size=15)
    plt.show()
    # plt.savefig('build/graph_out.png')



