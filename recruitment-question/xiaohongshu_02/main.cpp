#include <iostream>
#include <vector>

using namespace std;

void maxThumbsNum(vector<int> &notesList){
    int notesSize = notesList.size();
    if(notesSize == 0){
        return;
    }

    vector<int> thumbsNum(notesSize + 1, 0);
    vector<int> addThumbsNum(notesSize + 1, 0);
    thumbsNum[1] = notesList[0];
    addThumbsNum[1] = 1;

    for(int i = 2; i < notesSize + 1; ++i){
        if(thumbsNum[i-1] > thumbsNum[i-2] + notesList[i-1]){
            thumbsNum[i] = thumbsNum[i-1];
            addThumbsNum[i] = addThumbsNum[i-1];
        }else if(thumbsNum[i-1] == thumbsNum[i-2] + notesList[i-1]){
            if(addThumbsNum[i-1] < addThumbsNum[i-2] + 1){
                thumbsNum[i] = thumbsNum[i-1];
                addThumbsNum[i] = addThumbsNum[i-1];
            }else{
                thumbsNum[i] = thumbsNum[i-2] + notesList[i-1];
                addThumbsNum[i] = addThumbsNum[i-2] + 1;
            }
        }else{
            thumbsNum[i] = thumbsNum[i-2] + notesList[i-1];
            addThumbsNum[i] = addThumbsNum[i-2] + 1;
        }
    }

    cout << thumbsNum[notesSize] << " " << addThumbsNum[notesSize];
}

int main() {
    int noteNum = 0, tmp;
    cin >> noteNum;

    vector<int> noteList(noteNum, 0);
    for(int i = 0; i < noteNum; ++i){
        cin >> tmp;
        noteList[i] = tmp;
    }

    maxThumbsNum(noteList);
    return 0;
}