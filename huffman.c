// fail test. Actual complexity is O(nlognn) as extractmin() takens logn time.
void huffman(arr[],freq[],size)
{

    for(i=0;i<size;i++)
    {

        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

      struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    {

        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");

}
