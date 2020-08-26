# Depth First Search

- This type of search uses recursion (stack like structure) and there are 3 types of dfs, preorder, inorder, or postorder. 

## Preorder:
- preorder is when you read the data first before going to the left and right subtree

**Recursive Version**
```cpp

void preorder(Node *root) {
  if (root == nullptr) {
    read(root.data);
    preorder(root.left);
    preorder(root.right);
  }
}

```

**Iterative Version**
* This uses a stack data structure to track the nodes, but you actually also don't have to use a stack. It's just easier. 
* Source: https://stackoverflow.com/questions/38724489/intuitive-explanation-of-binary-tree-traversals-without-recursion

_using a stack_
```cpp


```

_not using a stack_

```java
/* code from stackoverflow: 
* source: https://stackoverflow.com/questions/38724489/intuitive-explanation-of-binary-tree-traversals-without-recursion
*/

void traversal(String typeOfTraversal){

    boolean visitedLeft = false;
    boolean visitedRight = false;
    TreeNode currentNode = this.root;

    while(true){

        if (visitedLeft == false && currentNode.leftChild != null){
            if(typeOfTraversal == "preOrder"){
                System.out.println(currentNode.key);
            }
            currentNode = currentNode.leftChild;
            continue;
        }

        if (visitedLeft == false && currentNode.leftChild == null){
            if(typeOfTraversal == "preOrder"){
                System.out.println(currentNode.key);
            }
            visitedLeft = true;
            continue;
        }

    }

```

## Inorder
- in order dfs is when you go to the left nodes first until there's no more left node, read the data before going to the right, if this is performed on a binary search tree, you will always be reading the values in an ascending sorted order


**Recursive Approach**
```cpp

void inorder(Node *root) {
  if (root == nullptr) {
    inorder(root.left);
    read(root.value);
    inorder(root.right);
  }
}

```

**Iterative Approach**

_with stack_

```cpp


```

_not with stack_

```java

void inorder(TreeNode* root) {

  boolean visitedLeft = false;
  boolean vistedRight = false;
  TreeNode currentNode = root;


  while (true) {
        if (visitedLeft == true && visitedRight == false && currentNode.rightChild != null){
            if(typeOfTraversal == "inOrder"){
                System.out.println(currentNode.key);
            }
            currentNode = currentNode.rightChild;
            visitedLeft = false;
            continue;
        }

        if (visitedLeft == true && visitedRight == false && currentNode.rightChild == null){
            if(typeOfTraversal == "inOrder"){
                System.out.println(currentNode.key);
            }
            visitedRight = true;
            continue;
        }
  }
}
```


## Postorder
- postorder dfs is when you read data last once you've gone down to left and the right node, so the right last child will be read first.

**Recursive Approach**
```cpp

void postorder(Node *root) {
  if (root == nullptr) {
    postorder(root.left);
    postorder(root.right);
    read(root.value);
  }
}
```

**Iterative Approach**

_using 2 stack_
```cpp




```

_not using stack_
```java

void traversal(String typeOfTraversal){

    boolean visitedLeft = false;
    boolean visitedRight = false;
    TreeNode currentNode = this.root;

    while(true){

        if (visitedLeft == true && visitedRight == true && currentNode.parent != null){
            if(typeOfTraversal == "postOrder"){
                System.out.println(currentNode.key);
            }

            if (currentNode == currentNode.parent.leftChild){
                visitedRight = false;
            }
            currentNode = currentNode.parent;
        }

        if (visitedLeft == true && visitedRight == true && currentNode.parent == null){       
            if(typeOfTraversal == "postOrder"){
                System.out.println(currentNode.key);
            }
            break; //Traversal is complete.
        }

    }
```