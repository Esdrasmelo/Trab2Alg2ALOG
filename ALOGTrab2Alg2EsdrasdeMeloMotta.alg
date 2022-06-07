Inicio
    Real: pesoMercadoria, valorEntrega, distanciaDestino, quilosExcedentes, pesoExcedente, valorEntregas_A, valorEntregas_T;
    Caracter: tipoEntrega;

    valorEntregas_A <- 0;
    valorEntregas_T <- 0;
    pesoMercadoria <- 0;
    quilosExcedentes <- 0;
    pesoExcedente <- 0;
    
    Leia(pesoMercadoria);

    Enquanto pesoMercadoria <> 0 Faça
        Inicio
            valorEntrega <- 0;

            Leia(tipoEntrega);

            Se tipoEntrega = "A" ou tipoEntrega = "a" Então
                Inicio
                    Se pesoMercadoria > 25 Então
                        Inicio
                            pesoExcedente <- (pesoMercadoria * 1000 - 25000) / 1000;
                            valorEntrega <- valorEntrega + (25 * 10.5) + pesoExcedente * (10.5 + 2.5);
                        Fim
                    Senão
                        valorEntrega <- valorEntrega + pesoMercadoria * 10.5;
                    
                    valorEntregas_A <- valorEntregas_A + valorEntrega;                    

                    Escreva(valorEntrega);
                Fim
                
            Se tipoEntrega = "T" ou tipoEntrega = "t" Então
                Inicio                    
                    Leia(distanciaDestino);
                    
                    Se distanciaDestino < 50 Então
                        valorEntrega <- pesoMercadoria * 3.5;
                    Se distanciaDestino >= 50 e distanciaDestino <= 150 Então
                        valorEntrega <- pesoMercadoria * 4.5;
                    Se distanciaDestino > 150 Então
                        valorEntrega <- pesoMercadoria * 6;

                    valorEntregas_T <- valorEntregas_T + valorEntrega;
                        
                    Escreva(valorEntrega);
                Fim
                
                Leia(pesoMercadoria);
        Fim

    Escreva(valorEntregas_A);
    Escreva(valorEntregas_T);
Fim
