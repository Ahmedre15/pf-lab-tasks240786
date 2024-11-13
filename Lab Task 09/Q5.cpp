#include<stdio.h>
#include<string.h>
int main(){
	int i=0,j=0;
	char sent[50];
	char key[20];
	char cipher[50];
	printf("Enter plain text : ");
	fgets(sent, sizeof(sent), stdin);
	sent[strcspn(sent, "\n")] = '\0';
	printf("Enter Key : ");
	scanf("%s",key);
	for(i=0;i<strlen(sent);i++){
		if (sent[i] >= 'a' && sent[i] <= 'z'){
		sent[i]=sent[i]-'a'+'A';
	}
	}
	for(i=0;i<strlen(key);i++){
		if (key[i] >= 'a' && key[i] <= 'z'){
		key[i]=key[i]-'a'+'A';
	}
	}
    for (i = 0; i < strlen(sent); i++) {
        cipher[i] = key[j];
        j++;
        if (j >= strlen(key)) {
            j = 0;  
        }
    }
    cipher[i] = '\0'; 
//        printf("\nOriginal Text (Uppercase): %s", sent);
//    printf("Key (Uppercase): %s\n", key);
//    printf("Cipher Text: %s\n", cipher);
    for(i=0;i<strlen(sent);i++){
		if (sent[i]!=' '){
	sent[i]=sent[i]-64;
	}
	}
	    for(i=0;i<strlen(cipher);i++){
	cipher[i]=cipher[i]-64;
	
	}
//printf("%d",sent[1]);
//printf("%d",cipher[1]);
char sum[50];
    for(i=0;i<strlen(cipher)-1;i++){
	sum[i]=cipher[i]+sent[i];
	}
//printf("%d\n",sum[0]);
//printf("%d\n",sum[1]);
//printf("%d\n",sum[2]);
for(i=0;i<strlen(sum);i++){
	sum[i]=sum[i]%26;
	}
//printf("%d\n",sum[0]);
//printf("%d\n",sum[1]);
//printf("%d\n",sum[2]);
for(i=0;i<strlen(sum);i++){
	sum[i]=sum[i]+64;
	}
//printf("%d\n",sum[0]);
//printf("%d\n",sum[1]);
//printf("%d\n",sum[2]);
printf("Our ciphertext would be:\n%s",sum);
}
