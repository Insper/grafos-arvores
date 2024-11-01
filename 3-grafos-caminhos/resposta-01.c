/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int **out = malloc(sizeof(int *) * matSize);
    for (int i = 0; i < matSize; i++) {
        out[i] = malloc(sizeof(int) * matColSize[i]);
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 0) {
                out[i][j] = 0;
            } else {
                out[i][j] =-1;
            }
        }
    }


    // TODO: resolver o problema
    int *qI = malloc(sizeof(int) * matSize * matColSize[0]);
    int *qJ = malloc(sizeof(int) * matSize * matColSize[0]);
    int qsz = 0;
    int qfront = 0;

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1 && (
                (i > 0 && mat[i-1][j] == 0) ||
                (i < matSize - 1  && mat[i+1][j] == 0) ||
                (j > 0 && mat[i][j-1] == 0) ||
                (j < matColSize[0] - 1 && mat[i][j+1] == 0)
            ) ) {
                qI[qsz] = i;
                qJ[qsz] = j;
                qsz++;
                out[i][j] = 1;
            }
        }
    }

    while (qsz > 0) {
        int i = qI[qfront];
        int j = qJ[qfront];
        qfront++;
        qsz--;

        if (i > 0 &&  out[i-1][j] == -1) {
            out[i-1][j] = out[i][j] + 1;
            
            qI[qsz + qfront] = i - 1;
            qJ[qsz  + qfront] = j;
            qsz++;
        } 

        if  (i < matSize - 1  && out[i+1][j] == -1) {
            out[i+1][j] = out[i][j] + 1;
            
            qI[qsz + qfront] = i + 1;
            qJ[qsz  + qfront] = j;
            qsz++;
        }

        if (j > 0 && out[i][j-1] == -1) {
            out[i][j-1] = out[i][j] + 1;
            
            qI[qsz + qfront] = i ;
            qJ[qsz  + qfront] = j-1;
            qsz++;

        }

        if (j < matColSize[0] - 1 && out[i][j+1] == -1) {
            out[i][j+1] = out[i][j] + 1;
            
            qI[qsz + qfront] = i ;
            qJ[qsz  + qfront] = j+1;
            qsz++;

        }       

    }


    *returnSize = matSize;

    // usou malloc para devolver array
    int *retColSize = malloc(sizeof(int) * matSize);
    for(int i = 0; i < matSize; i++) {
        retColSize[i] = matColSize[i];
    }
    *returnColumnSizes = retColSize;
    return out;
}
