/* Trabalho realizado por Gabriella Alves de Oliveira */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXIMO 1000 //limite de produtos cadastrados

typedef struct{

    char nome[50]; //chave de busca
    int index; //indica a posição dos detalhes do produto na INFOS

}CHAVE;

typedef struct {
    
    int deletado; //1 = deletado, -1 = nn deletado
    float valor_compra;
    float valor_venda;
    int quant_estoque; //quantidade do produto no estoque
    int quant_vendido; //quantidade vendida do produto

}INFOS;

/////////////////////////////////////////////////////////////////////////////////

void inicializacao(CHAVE* key, INFOS* informacao, int* cont, int* tam_infos);
void ler_arquivo(INFOS* informacao, FILE* fInfos, CHAVE* key, FILE* fChave, int *cont, int* tam_infos);
void vender(CHAVE* key, int cont, INFOS* informacao);
void cadastrar_novo_produto (CHAVE* key, INFOS* informacao, int* cont, int* tam_infos);
void partition(int esquerda, int direita, int *i, int *j, CHAVE *v);
void quicksort(CHAVE *v, int n);
void sort(int esquerda, int direita, CHAVE *v);
void remover_produto_do_estoque(CHAVE* key, int* cont, INFOS* informacao, int* all_produtos, float* lucro);
void consultar_estoque(CHAVE* key, INFOS* informacao, int cont);
void consultar_lucro(CHAVE* key, INFOS* informacao, int cont);
void repor_estoque(CHAVE* key, INFOS* informacao, int cont);
int busca_binaria(char *produto, CHAVE *key, int low, int high);
void finalizacao(CHAVE* key, int cont, INFOS* informacao, int all_produtos, float lucro);

/////////////////////////////////////////////////////////////////////////////////

int main(){

    int option;
    int cont = 0;
    int tam_infos = 0;
    int all_produtos = 0;
    float lucro = 0;
    FILE *fChave;
    FILE *fInfos;
    CHAVE *key;
    INFOS *informacao;

    key = (CHAVE*) malloc (MAXIMO * sizeof(CHAVE));
    informacao = (INFOS*) malloc (MAXIMO * sizeof(INFOS*));
    
    fChave = fopen("chave.bin", "r+b");

    if (fChave == NULL){

        fChave = fopen("chave.bin", "w+b");
        fInfos = fopen("infs.bin", "w+b");
        inicializacao(key, informacao, &cont, &tam_infos);
        quicksort(key, cont);

    }

    else {
        fInfos = fopen("infs.bin", "r+b");
        ler_arquivo(informacao, fInfos, key, fChave, &cont, &tam_infos);
    }

    while (1){

        printf("\n-----------------------------\n");
        printf("\n\tMENU\n\n");
        printf("1 - Vender\n");
        printf("2 - Cadastrar novo produto\n");
        printf("3 - Remover produto do estoque\n");
        printf("4 - Consultar estoque\n");
        printf("5 - Consultar lucro\n");
        printf("6 - Repor estoque\n");
        printf("0 - Sair\n"); // escrever nos arquivos todas as manipulacoes feitas no programa
        printf("\nOpcao: ");
        scanf("%d", &option);

        switch (option){

            case 1:{
                vender(key, cont, informacao);
                break;
            }

            case 2:{
                cadastrar_novo_produto(key, informacao, &cont, &tam_infos);
                quicksort(key, cont);
                break;
            }

            case 3:{
                remover_produto_do_estoque(key, &cont, informacao, &all_produtos, &lucro);
                break;
            }

            case 4:{
                consultar_estoque(key, informacao, cont);
                break;
            }

            case 5:{
                consultar_lucro(key, informacao, cont);
                break;
            }

            case 6:{
                repor_estoque(key, informacao, cont);
                break;
            }

            case 0:{
                finalizacao(key, cont, informacao, all_produtos, lucro);
                fChave = fopen("chave.bin", "w+b");
                fInfos = fopen("infs.bin", "w+b");
                for (int i = 0; i < tam_infos; i++){

                    fwrite(&informacao[i].deletado, sizeof(int), 1, fInfos);
                    fwrite(&informacao[i].valor_compra, sizeof(float), 1, fInfos);
                    fwrite(&informacao[i].valor_venda, sizeof(float), 1, fInfos);
                    fwrite(&informacao[i].quant_estoque, sizeof(int), 1, fInfos);
                    fwrite(&informacao[i].quant_vendido, sizeof(int), 1, fInfos);
                
                }

                fclose(fInfos);

                for (int i = 0; i < cont; i++){
                
                    fwrite(key[i].nome, sizeof(char), 50, fChave);
                    fwrite(&key[i].index, sizeof(int), 1, fChave);

                }

                fclose(fChave);

                printf("\nFinalizando programa...\n");
                return 0;
            }

            default:{
                printf("\nERRO: Opcao invalida!\n");
                break;
            }   

        }
    
    }
    
}

void inicializacao(CHAVE* key, INFOS* informacao, int* cont, int* tam_infos){

    char continuar = 'S';
    int i=0;

    printf("PRIMEIRA EXECUCAO\n");
    
    while(1){

        printf("\nInsira o nome do produto: ");
        scanf(" %[^\n]%*c", key[i].nome);

        for (int l = 0; l < strlen(key[i].nome); l++){
            
            if (key[i].nome[l] != ' '){
            
                key[i].nome[l] = toupper(key[i].nome[l]);
            
            }

        }

        key[i].index = i * (sizeof(INFOS));
        informacao[i].deletado = -1;

        printf("\nInsira o valor de compra: ");
        scanf("%f", &informacao[i].valor_compra);

        printf("\nInsira o valor de venda: ");
        scanf("%f", &informacao[i].valor_venda);

        printf("\nInsira a quantidade no estoque: ");
        scanf("%d", &informacao[i].quant_estoque);

        printf("\nInsira a quantidade ja vendida: ");
        scanf("%d", &informacao[i].quant_vendido);

        (*cont)++;
        (*tam_infos)++;

        while (1){

            printf("\nDeseja continuar registrando? (S/N)\n");
            scanf(" %c", &continuar);
            if (continuar == 'S' || continuar == 's') break;

            else if (continuar == 'N' || continuar == 'n') return;
            
            else printf("\nOpcao invalida, tente novamente.");
            
        }

        i++;

    }

}

void ler_arquivo(INFOS* informacao, FILE* fInfos, CHAVE* key, FILE* fChave, int *cont, int* tam_infos){

    while(fread(&informacao[*tam_infos].deletado, sizeof(int), 1, fInfos) != 0){

        fread(&informacao[*tam_infos].valor_compra, sizeof(float), 1, fInfos);
        fread(&informacao[*tam_infos].valor_venda, sizeof(float), 1, fInfos);
        fread(&informacao[*tam_infos].quant_estoque, sizeof(int), 1, fInfos);
        fread(&informacao[*tam_infos].quant_vendido, sizeof(int), 1, fInfos);
        
        (*tam_infos)++;

    }
    fclose(fInfos);

    while((fread(key[*cont].nome, sizeof(char), 50, fChave)) != '\0'){

        fread(&key[*cont].index, sizeof(int), 1, fChave);

        (*cont)++;

    }

    fclose(fChave);

    return;

}

void vender(CHAVE* key, int cont, INFOS* informacao){ 

    char *produto;
    int aux;

    produto = (char*) malloc (50*sizeof(char));

    printf("\nInsira o nome do produto: ");
    scanf("%[^\n]%*c", produto);

    for (int i = 0; i < strlen(produto); i++){

        if (produto[i] != ' '){
            
            produto[i] = toupper(produto[i]);
            
        }

    }
    

    int aux1 = busca_binaria(produto, key, 0, cont);

    if (aux1 < 0){

        printf("\nERRO: Produto nao encontrado.");
        return;

    }

    int aux2 = key[aux1].index/sizeof(INFOS);

    printf("\nInsira a quantidade: ");
    int quantidade;
    scanf("%d", &quantidade);

    if (informacao[aux2].quant_estoque < quantidade) {

        printf("\nNao ha estoque disponivel para atender a venda.\n");
        return;

    }

    if (quantidade <= 0){
        printf("\nQuantidade insuficiente.");
        return;
    }
    
    float total = quantidade * informacao[aux2].valor_venda;
    printf("\nValor total da venda: %.2f\n", total);
    informacao[aux2].quant_estoque-=quantidade;
    informacao[aux2].quant_vendido+=quantidade;
    return;

}

void cadastrar_novo_produto(CHAVE* key, INFOS* informacao, int* cont, int* tam_infos){ 

    char continuar = 'S';
    int i = *cont, j = 0;
    char *produto;

    produto = (char*) malloc (50 * sizeof(char));

    while(1){

        printf("\nInsira o nome do produto: ");
        scanf(" %[^\n]%*c", produto);

        for (int l = 0; l < strlen(produto); l++){
            
            if (produto[l] != ' '){
            
                produto[l] = toupper(produto[l]);
            
            }

        }
        int n = *cont;
        int aux1 = busca_binaria(produto, key, 0, n);

        if (aux1 < 0){

            strcpy(key[i].nome, produto);

        }
        else{
            
            printf("\nProduto ja existe.");
            return;

        }
            
        while (1){
        
            if (informacao[j].deletado == -1) j++;

            else {

                if(informacao[j].deletado == 0){
                    (*tam_infos)++;
                    break;
                }
                
                break;

            }
            
        }

        key[i].index = j * (sizeof(INFOS));
        informacao[j].deletado = -1;

        printf("\nInsira o valor de compra: ");
        scanf("%f", &informacao[j].valor_compra);

        printf("\nInsira o valor de venda: ");
        scanf("%f", &informacao[j].valor_venda);

        printf("\nInsira a quantidade no estoque: ");
        scanf("%d", &informacao[j].quant_estoque);

        printf("\nInsira a quantidade ja vendida: ");
        scanf("%d", &informacao[j].quant_vendido);

        (*cont)++;
        
        while (1){

            printf("\nDeseja continuar registrando? (S/N)\n");
            scanf(" %c", &continuar);
            if (continuar == 'S' || continuar == 's') break;

            else if (continuar == 'N' || continuar == 'n') return;
            
            else printf("\nOpcao invalida, tente novamente.");
            
        }

        i = *cont;
        j=0;

    }

}

void partition(int esquerda, int direita, int *i, int *j, CHAVE *v){

  CHAVE x, w;

  *i = esquerda; *j = direita;

  x = v[(*i + *j)/2];

    do{           
        while(strcmp(x.nome, v[*i].nome) > 0)
            (*i)++;
        while(strcmp(x.nome, v[*j].nome) < 0)
            (*j)--;

        if (*i <= *j){
            w = v[*i];
            v[*i] = v[*j];
            v[*j] = w;
            (*i)++;
            (*j)--;
        }

    } while (*i <= *j);
}

void sort(int esquerda, int direita, CHAVE *v){
    int i,j;

    partition(esquerda, direita, &i, &j, v);

    if (esquerda < j) sort(esquerda, j, v);
    if (i < direita) sort(i, direita, v);

}

void quicksort(CHAVE *v, int n){
    sort(0, n-1, v);
}

void remover_produto_do_estoque(CHAVE* key, int* cont, INFOS* informacao, int* all_produtos, float* lucro){ 

    char *produto;

    produto = (char*) malloc (50*sizeof(char));

    printf("\nInsira o nome do produto que deseja remover: ");
    scanf(" %[^\n]%*c", produto);

    for (int i = 0; i < strlen(produto); i++){

        if (produto[i] != ' '){
            
            produto[i] = toupper(produto[i]);
            
        }

    }

    int m = *cont;
    int aux1 = busca_binaria(produto, key, 0, m);

    if (aux1 < 0){

        printf("\nERRO: Produto nao encontrado.");
        return;

    }

    int aux2 = key[aux1].index/sizeof(INFOS);

    (*cont)--;
    
    for (int i = aux1; i < (*cont); i++){
        strcpy(key[i].nome, key[i+1].nome);
        key[i].index = key[i+1].index;
    }
    
    informacao[aux2].deletado = 1;
    (*all_produtos) += informacao[aux2].quant_vendido;
    (*lucro) += informacao[aux2].quant_vendido * informacao[aux1].valor_venda;

    int n = *cont;
    quicksort(key, n);

    return;

}

void consultar_estoque(CHAVE* key, INFOS* informacao, int cont){

    float aux = 0;

    for (int i = 0; i < cont; i++){
        
        printf("\nProduto: %s", key[i].nome);
        int j = key[i].index/sizeof(INFOS);
        float k = informacao[j].quant_estoque * informacao[j].valor_venda;
        printf("\nValor total em estoque: R$ %.2f\n", k);

        aux += k;

    }

    printf("\n\nValor total do estoque: R$ %.2f\n", aux);

    return;

}

void consultar_lucro(CHAVE* key, INFOS* informacao, int cont){  // seguindo as instrucoes do professor

    for (int i = 0; i < cont; i++){
        
        printf("\nProduto: %s", key[i].nome);
        int j = key[i].index/sizeof(INFOS);
        float k = informacao[j].quant_vendido * informacao[j].valor_venda;
        printf("\nLucro: R$ %.2f\n", k);

    }
    
    return;

}

void repor_estoque(CHAVE* key, INFOS* informacao, int cont){

    char *produto;
    int aux1, aux2;

    produto = (char*) malloc (50 * sizeof(char));

    printf("\nInsira o produto que deseja repor o estoque: ");
    scanf(" %[^\n]%*c", produto);

    for (int i = 0; i < strlen(produto); i++){

        if (produto[i] != ' '){
            
            produto[i] = toupper(produto[i]);
            
        }
        
    }
    
    aux1 = busca_binaria(produto, key, 0, cont);

    if (aux1 < 0){

        printf("\nERRO: Produto nao encontrado.");
        return;

    }

    aux2 = key[aux1].index/sizeof(INFOS);
    
    int quantidade;
    printf("\nInsira quanto deseja repor no estoque: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0){
        printf("\nQuantidade insuficiente.\n");
        return;
    }
    
    informacao[aux2].quant_estoque += quantidade;

    printf("\nO novo estoque de %s eh: %d\n", key[aux1].nome, informacao[aux2].quant_estoque);

    return;

}

int busca_binaria(char *produto, CHAVE *key, int low, int high){   //high = tamanho de key
    int indice, x;

    if (low > high) return -1;
    indice = (low + high) / 2;
    x = strcmp( produto, key[indice].nome);
    if (x == 0 ) 
        return indice;
    if (x < 0) 
        return busca_binaria( produto, key, low, indice - 1); 
    else 
        return busca_binaria( produto, key, indice + 1, high); 
}

void finalizacao(CHAVE* key, int cont, INFOS* informacao, int all_produtos, float lucro){

    int aux = 0;
    float lucro2 = 0;

    for (int i = 0; i < cont; i++){

        int j = key[i].index/sizeof(INFOS);
        aux += informacao[j].quant_vendido;

    }

    printf("\nA cantina vendeu %d produtos.", aux);
    int aux2 = aux + all_produtos;
    printf("\nA cantina vendeu (contando os itens excluidos ao longo desta execucao): %d produtos.", aux2); //considerando os itens excluidos

    for (int i = 0; i < cont; i++){
        
        printf("\n\nProduto: %s", key[i].nome);
        int j = key[i].index/sizeof(INFOS);
        printf("\nQuantidade vendida do produto: %d", informacao[j].quant_vendido);
        printf("\nEstoque restante do produto: %d", informacao[j].quant_estoque);
        printf("\nValor de venda do produto: %.2f", informacao[j].valor_venda);
        float k = informacao[j].quant_estoque * informacao[j].valor_venda;
        printf("\nValor total em estoque: R$ %.2f\n", k);
        lucro2 += informacao[j].valor_venda * informacao[j].quant_vendido;

    }

    float lucro3 = lucro2 + lucro;
    printf("\nLucro total do dia: R$ %.2f\n", lucro3); //considerando os itens excluidos

    return;

}
