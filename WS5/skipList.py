# from random import randint, seed 
import random 



class Node:
    def __init__(self, height=0, elem=None):
        self.elem = elem
        self.next = [None]*(height+1) 

class SkipList:
    def __init__(self, max_lvl, P):
        self.head = self.createNode(self.MAXLVL, -1)
        self.P = P
        self.MAXLVL = max_lvl;

    def __len__(self):
        return self.len 
    
    def createNode(self, lvl, key):
        n = Node(key, lvl)
        return n 
    
    def randomLevel(self):
        lvl = 0
        while random.random() < self.P and lvl < self.MAX:
            lvl+=1
        return lvl 
    
    
    
    
    
    def find(self, elem, update=None):
        if update == None:
            update = self.updateList(elem)
        if len(update) > 0:
            item = 0 
    
    def search(self, key):
        current = self.header 
        for level in range(self.level, -1, -1):
            while current.forward[level] and current.forward[level].key < key:
                current = current.forward[level]
        current = current.forward[0]
        if current and current.key == key:
            print(f"Foiund key: {key}")
    
    # def contains(self, elem, update, update=None):
        # pass 

    def randomHeight(self):
        pass 

    def updateList(self, elem):
        pass 

    def insert(self, elem):
        pass 

    def remove(self, elem):
        pass 

    def printList(self):
        pass 

#    https://gist.github.com/sachinnair90/3bee2ef7dd3ff0dc5aec44ec40e2d127



###############BEST###########
# https://medium.com/@remisharoon/advanced-data-structures-series-skip-list-3819ea2f7fa0
# https://skiplist.readthedocs.io/en/latest/introduction.html
# https://pypi.org/project/orderedstructs/
# https://skiplist.readthedocs.io/en/latest/visualisations.html#skiplist-visualisation-label



# https://github.com/kunigami/blog-examples/blob/master/skip-list/skipList.py

# https://runestone.academy/ns/books/published/pythonds3/Advanced/DictionariesRevisited.html



# Building a skip list 
# https://blog.jnbrymn.com/2018/09/16/build-your-own-skip-list.html
# https://github.com/ZhukovAlexander/py-skiplist
