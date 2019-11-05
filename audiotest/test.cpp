//
//  test.cpp
//  PCM3.0    ����Ч�ʵ� ����ʮ������
//  ����ʱ����ͼ��������������ֵ�Ĵ�С��
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct wav_struct
{
    unsigned long file_size;       //�ļ���С
    unsigned short channel;        //ͨ����
    unsigned long frequency;       //����Ƶ��
    unsigned long Bps;             //Byte��
    unsigned short sample_num_bit; //һ��������λ��
    unsigned long data_size;       //���ݴ�С
    unsigned char *data;           //��Ƶ����
};

int printstar2(double p1)
{
    int p = p1;
    if (p < 0 && p > -50)
    {
        for (int i = 0; i < (50 + p); i++)
        {
            cout << " ";
        }
        for (int i = 0; i < (-p); i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    else if (p == 0)
    {
        for (int i = 0; i < 50; i++)
        {
            cout << " ";
        }

        cout << "|";
        cout << endl;
    }
    else if (p > 0)
    {
        for (int i = 0; i <= 50; i++)
        {
            cout << " ";
        }
        for (int i = 0; i < p; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    else
        cout << p << endl;
}

int main(int argc, char **argv)
{
    fstream fs;
    wav_struct WAV;

    fs.open("./Alarm02.wav", ios::binary | ios::in); //Ҫ��������Ƶ�ļ�·����������Դ����Ŀ¼�µ�dogbarks.wav�ļ�

    fs.seekg(0, ios::end); //��c++���÷�������ļ���С
    WAV.file_size = fs.tellg();

    fs.seekg(0x14);
    fs.read((char *)&WAV.channel, sizeof(WAV.channel));

    fs.seekg(0x18);
    fs.read((char *)&WAV.frequency, sizeof(WAV.frequency));

    fs.seekg(0x1c);
    fs.read((char *)&WAV.Bps, sizeof(WAV.Bps));

    fs.seekg(0x22);
    fs.read((char *)&WAV.sample_num_bit, sizeof(WAV.sample_num_bit));

    fs.seekg(0x28);
    fs.read((char *)&WAV.data_size, sizeof(WAV.data_size));

    WAV.data = new unsigned char[WAV.data_size];

    fs.seekg(0x2c);
    fs.read((char *)WAV.data, sizeof(char) * WAV.data_size);
    
//FFTW
    fftw_complex *in,*out;
    fftw_plan p;
    in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*n);
    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*n);
    if (in==NULL||out==NULL) {
        cout<<"ERROR: Fail to memory allocation"<<endl;
    }else{
        int  i=0;
        for(vector<float>::iterator it = vertices.begin(); it != vertices.end(); it+=2 ){
            in[i][0]=*it;
            in[i][1]=0.0;
            i++;
        }
    }
    p = fftw_plan_dft_1d(n, in, out, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(p);
    fftw_destroy_plan(p);
    fftw_cleanup();
    
    int m = 0;
    for (unsigned long i = 0; i < WAV.data_size; i = i + 400) //�ɵ��ڴ�ӡ����
    {
        //�ұ�Ϊ���
        unsigned long data_low = WAV.data[i];
        unsigned long data_high = WAV.data[i + 1];
        double data_true = data_high * 256 + data_low;
        long data_complement = 0;
        //ȡ��˵����λ������λ��
        int my_sign = (int)(data_high / 128);

        if (my_sign == 1)
        {
            data_complement = data_true - 65536;
        }
        else
        {
            data_complement = data_true;
        }

        setprecision(4);
        double float_data = (double)(data_complement / (double)32768);
        double starnumber1 = float_data * 100;
        printstar2(starnumber1);
        //printf("%f ", float_data);
        Sleep(10); //������Ļ�����ٶ�
        m++;
    }
    fs.close();
    cout << "�ļ���СΪ  ��" << WAV.file_size << endl;
    cout << "��Ƶͨ����  ��" << WAV.channel << endl;
    cout << "����Ƶ��    ��" << WAV.frequency << endl;
    cout << "Byte��      ��" << WAV.Bps << endl;
    cout << "����λ��    ��" << WAV.sample_num_bit << endl;
    cout << "��Ƶ���ݴ�С��" << WAV.data_size << endl;
    cout << "�ܼƴ�ӡ������" << m << endl;

    delete[] WAV.data;
    int n;
    cout << "���ֵ����ִ������ǵ���������������ֵ��������";
    cin >> n;
}