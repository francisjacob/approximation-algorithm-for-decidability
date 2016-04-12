//not sure
void floodFillUtil(screen[][N],prevC,newC,x,y)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;

    // Replace the color at (x, y)
    screen[x][y] = newC;

    // Recur for north, east, south and west
    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);

    floodFillUtil(screen, x, y-1, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
}
