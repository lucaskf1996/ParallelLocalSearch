# Algoritmo para alinhamento de sequências de DNA com aleatoriedade
Sendo i o índice do início da substring A, j o índice do início da substring B, n o tamanho da substring A, m o tamanho da substring B, k o tamanho das substrings e p a quantidade de substrings geradas em B, utiliza-se o pseudo-código abaixo para fazer os alinhamentos:

1. Gerar uma subsequencia sb=b[j,j+1,...,j+k] de b, de tamanho aleatório k, 1<=k<=m, e 0<=j<=m 
2. Gerar um número aleatório inteiro positivo p
3. Gerar p subsequencias sa=a[i,i+1,...,i+k] de a, com tamanho k calculado no passo (1), 0<=i<=n
4. Calcular os scores de cada par (sa,sb) com os pesos wmat, wmis e wgap
5. Devolver o score máximo m entre os scores do passo (4) e as subsequencias associadas a ele

Alguns tratamentos foram efetuados para que o programa funcione corretamente. Primeiramente verifica-se qual a menor sequência entre as duas que serviram de entrada para o cálculo do valor k, evitando que este seja maior que o tamanho de uma das sequências originais. Outro tratamento é que os valores de j devem ser entre 0 e m-k. Os valores de j, k e p são gerados aleatóriamente. Além disso, os valores de wmat, wmis, wgap são os mesmos utilizados no outro projeto (https://github.com/lucaskf1996/SmithWaterman) para que uma comparação possa ser feita eventualmente.
Outras obsevações a serem feitas é que o cálculo do score é feito de caractere em caractere, podendo ter um resultado negativo e que i foi mantido como 0, mas que pode ser facilmente modificado para adicionar mais aleatoriedade à solução.
