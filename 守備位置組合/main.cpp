/*
�D��: �u�Ʀ�m�զX

�G��:
�����D�`������,�䤤���@�ӭ�]�O�]���L�D�`è�g��q�y,�C��§������H�m�߭ӤT�|�ѥL�N�|������
�ΪA�C�̪�L��o�_�Q,�Q�n��H�Ӳդ@���S�y��,�u���L��Ӫ��H���O�p�o�o,�u��u�ƥL�̫��w����m
�]���Q�ЧA�����վ㶤��C

����:
�`�@��n�ӤH�Mm�ӻݭn����m,n�@�w�j����m�C
�ѩ�C�ӤH�u��u�Ƥ@�Ӧ�m,�B�C�ӤH�����L�i�H�P���i�H����m,���U�i���C�ӤH��u����m,
0�N���i�H,1�N��i�H�u�ƸӦ�m�C
��X�`�@���X�ت��p�O�Ҧ���m�������Ѥ@�H�u�ơC

��J����:
�Ĥ@���Jm�N���U��n���J,�C�@��Ѫ��׬�m��0�P1�ժ��Ʀr�C

��X����:
�`�@���X�ئu�ƲզX

�d�ҿ�J:
4 3
001
101
010
111

�d�ҿ�X:
5
*/
#include <iostream>

using namespace std;

bool table[100][100];
int n,m;
int sum;

void check(int x, int now[])
{
    bool success;
    int i,j;
    if (x>m) {
        sum++;
    } else {
        for (i=1;i<=n;i++) {
            if (table[i][x]==true) {
                success=true;
                for (j=1;j<=x-1;j++)
                    if (now[j]==i) {
                        success=false;
                        break;
                    }
                if (success==true) {
                    int now2[100];
                    for (j=1;j<=x-1;j++) now2[j]=now[j];
                    now2[x]=i;
                    check(x+1, now2);
                }
            }
        }
    }
}

int main()
{
    int i,j;
    int temp[100]={0};
    string input;
    cin >> n >> m;
    for (i=1;i<=n;i++) {
        cin >> input;
        for (j=1;j<=m;j++)
            table[i][j]=input[j-1]-'0';
    }

    sum=0;
    check(1, temp);

    cout << sum;
    return 0;
}
