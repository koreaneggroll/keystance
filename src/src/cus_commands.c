#include "../custom/commands/cus_commands.h"


void cus_cmd_time(){
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    editorSetStatusMessage("Local time and date: %s", asctime(timeinfo));
}


void cus_cmd_weather(){
    


}


void cus_cmd_google(){
    char *cmd = (char*)malloc(sizeof(char) * 100);
    char *search = editorPrompt("search: %s", NULL);

    if(!search){
        editorSetStatusMessage("%sERROR!%s 'search' variable ran out of memory", red(), white());
    }


    if(!cmd){
        editorSetStatusMessage("%SERROR!%s 'cmd' variable ran out of memory", red(), white());
    }


    for(int i = 0; i < strlen(search); i++){
        if(search[i] == ' '){
            search[i] = '+';
        }
    }



    strcpy(cmd, "firefox https://google.com/search?q=");
    strcat(cmd, search);


    system(cmd);
}


void cus_cmd_wiki(){

}