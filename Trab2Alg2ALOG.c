#include <stdio.h>

float calcularValorEntregaAerea(float pesoMercadoria)
{
    float pesoExcedente;

    pesoExcedente = 0;

    if (!pesoMercadoria > 25) return pesoMercadoria * 10.5;

    pesoExcedente = pesoExcedente + (pesoMercadoria * 1000 - 25000) / 1000;

    return 25 * 10.5 + pesoExcedente * (10.5 + 2.5);
}

float calcularEntregaTerrestre(float pesoMercadoria, float distanciaDestino)
{
    if (distanciaDestino < 50) return pesoMercadoria * 3.5;

    if (distanciaDestino >= 50 && distanciaDestino <= 150) return pesoMercadoria * 4.5;

    if (distanciaDestino > 150) return pesoMercadoria * 6;
}

void main(void)
{
    float pesoMercadoria, valorEntregaAerea, valorEntregaTerrestre, distanciaDestino, valorEntregas_A, valorEntregas_T;
    char tipoEntrega;

    pesoMercadoria = 0;
    valorEntregas_A = 0;
    valorEntregas_T = 0;


    printf("\nDigite o peso da mercadoria: ");
    scanf(" %f", &pesoMercadoria);

    while (pesoMercadoria != 0)
    {
        printf("Digite o tipo de entrega: ");
        scanf(" %c", &tipoEntrega);

        if (tipoEntrega == 'A' || tipoEntrega == 'a')
        {
            valorEntregaAerea = calcularValorEntregaAerea(pesoMercadoria);
            valorEntregas_A = valorEntregas_A + valorEntregaAerea;

            printf("\nValor da entrega: R$%.2f\n", valorEntregaAerea);
        }

        if (tipoEntrega == 'T' || tipoEntrega == 't')
        {
            printf("Digite a distância do destinatario: ");
            scanf(" %f", &distanciaDestino);

            valorEntregaTerrestre = calcularEntregaTerrestre(pesoMercadoria, distanciaDestino);
            valorEntregas_T = valorEntregas_T + valorEntregaTerrestre;
            
            printf("\nValor da entrega: R$%.2f\n", valorEntregaTerrestre);
        }

        printf("\nDigite o peso da mercadoria: ");
        scanf(" %f", &pesoMercadoria);
    }

    printf("\nValor total das entregas aereas: R$%.2f\n", valorEntregas_A);
    printf("Valor total das entregas terrestres: R$%.2f\n", valorEntregas_T);
}