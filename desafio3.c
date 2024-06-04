#include <stdio.h>

#define MAX 50

// Vetores para representar os deslocamentos nas direções x e y para os vizinhos
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	
	// Mikael Henrique Lino Rodrigues  RA: 2760482321047
	// Victor Benatti Alves Dos Santos RA: 2760482321030
    
    /* A finalidade deste código é simular um apocalipse zumbi, de modo a prever o destino de um individuo através de uma 
	grade (matriz), onde um indivíduo X que esteja numa posição (i,j) desta matriz, tem como vizinhos àqueles nas posições 
	(i-1,j-1), (i-1,j), (i-1,j+1), (i,j-1), (i,j+1), (i+1,j-1), (i+1,j), (i+1,j+1). Ou seja, o objetivo deste exercício é, 
	dada a configuração inicial da população, simular o estado da população durante alguns dias no apocalipse. Dois inteiros 
	(m e n) compôem a primeira linha da entrada, onde m=linhas e n=colunas da matriz. Já a segunda linha é composta por um
	inteiro i, o qual representa o número de dias que se deseja simular o estado da população. Em seguida teremos as m linhas
	da matriz, onde 0=vazio, 1=humano e 2=zumbi. A saída reportará o estado da população para cada um dos dias. Para cada estado 
	a ser impresso, será apresentado primeiramente a interacao x, onde x será substituido pelo dia que foi simulado e em seguida
	a matriz impressa. */
	
    int m, n, i, j, k, d;
    int grid[MAX][MAX], temp[MAX][MAX];

    // Entrada das dimensões da matriz
    printf("Insira as dimensões da matriz: ");
    scanf("%d %d", &m, &n);

    // Verificações de entrada para garantir dimensões válidas
    if (m <= 0 || n <= 0 || m > MAX || n > MAX) {
        printf("Dimensões inválidas. Certifique-se de que 0 < m, n <= %d\n", MAX);
        return 1;
    }

	// Entrada do número de dias para simulação
    printf("Insira a quantidade de dias que se deseja simular o estado da população: ");
    scanf("%d", &d);

    // Verificação de entrada para garantir que o número de dias não seja negativo
    if (d < 0) {
        printf("O número de dias não pode ser negativo.\n");
        return 1;
    }

    // Entrada da configuração inicial da população na matriz
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Impressão do estado inicial da população
    printf("Iteracao 0\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Simulação para cada dia
    for (int day = 1; day <= d; day++) {
        printf("Iteracao %d\n", day);

        // Loop para cada célula na matriz
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                int v, z = 0, h = 0, e = 0;

                // Loop para verificar os vizinhos ao redor da célula atual
                for (k = 0; k < 8; k++) {
                    // Cálculo das coordenadas do vizinho com tratamento de borda
                    int ni = (i + dx[k] + m) % m;
                    int nj = (j + dy[k] + n) % n;
                    v = grid[ni][nj];
                    z += (v == 2);  // Contagem de zumbis
                    h += (v == 1);  // Contagem de humanos
                    e += (v == 0);  // Contagem de espaços vazios
                }

                // Aplicação das regras de transição para atualizar a célula no próximo dia
                if (grid[i][j] == 1 && z >= 1)
                    temp[i][j] = 2;  // Humano é infectado por zumbis
                else if (grid[i][j] == 2 && (h >= 2 || h == 0))
                    temp[i][j] = 0;  // Zumbi morre de solidão ou por humanos
                else if (grid[i][j] == 2 && h == 0)
                    temp[i][j] = 0;  // Zumbi morre de fome
                else if (grid[i][j] == 0 && h == 2)
                    temp[i][j] = 1;  // Espaço vazio é ocupado por humano
                else
                    temp[i][j] = grid[i][j];  // Nenhuma mudança

            }  // Fim do loop nas colunas
        }      // Fim do loop nas linhas

        // Atualizar o estado do planeta para o próximo dia
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                grid[i][j] = temp[i][j];
            }
        }

        // Imprimir o estado atualizado
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }  // Fim do loop para cada dia

    return 0;
}