    for (int i=0;i<ftime.size();i++) {
        if (stoi(ftime[i].substr(ftime[i].find("n")+1,ftime[i].find("h")-1))==response) {
            int hour=stoi(ftime[i].substr(ftime[i].find("h")+1,ftime[i].find("m")-1));
            int minute=stoi(ftime[i].substr(ftime[i].find("m")+1,ftime[i].find("s")-1));
            int second=stoi(ftime[i].substr(ftime[i].find("s")+1,ftime[i].length()));
            sensor1=(hour*60*60)+(minute*60)+second;
        }
    }

    for (int i=0;i<stime.size();i++) {
        if (stoi(stime[i].substr(stime[i].find("n")+1,stime[i].find("h")-1))==response) {
            int hour=stoi(stime[i].substr(stime[i].find("h")+1,stime[i].find("m")-1));
            int minute=stoi(stime[i].substr(stime[i].find("m")+1,stime[i].find("s")-1));
            int second=stoi(stime[i].substr(stime[i].find("s")+1,stime[i].length()));
            sensor2=(hour*60*60)+(minute*60)+second;
        }
    }

    for (int i=0;i<ttime.size();i++) {
        if (stoi(ttime[i].substr(ttime[i].find("n")+1,ttime[i].find("h")-1))==response) {
            int hour=stoi(ttime[i].substr(ttime[i].find("h")+1,ttime[i].find("m")-1));
            int minute=stoi(ttime[i].substr(ttime[i].find("m")+1,ttime[i].find("s")-1));
            int second=stoi(ttime[i].substr(ttime[i].find("s")+1,ttime[i].length()));
            sensor3=(hour*60*60)+(minute*60)+second;
        }
    }