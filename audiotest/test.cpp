//
//  test.cpp
//  PCM3.0    解码效率低 卡顿十分严重
//  绘制时域波形图，星星数量代表值的大小。
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

struct wav_struct
{
    unsigned long file_size;       //文件大小
    unsigned short channel;        //通道数
    unsigned long frequency;       //采样频率
    unsigned long Bps;             //Byte率
    unsigned short sample_num_bit; //一个样本的位数
    unsigned long data_size;       //数据大小
    unsigned char *data;           //音频数据
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

    fs.open("./Alarm02.wav", ios::binary | ios::in); //要分析的音频文件路径，这里是源程序目录下的dogbarks.wav文件

    fs.seekg(0, ios::end); //用c++常用方法获得文件大小
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
    for (unsigned long i = 0; i < WAV.data_size; i = i + 400) //可调节打印行数
    {
        //右边为大端
        unsigned long data_low = WAV.data[i];
        unsigned long data_high = WAV.data[i + 1];
        double data_true = data_high * 256 + data_low;
        long data_complement = 0;
        //取大端的最高位（符号位）
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
        Sleep(10); //调节屏幕滚动速度
        m++;
    }
    fs.close();
    cout << "文件大小为  ：" << WAV.file_size << endl;
    cout << "音频通道数  ：" << WAV.channel << endl;
    cout << "采样频率    ：" << WAV.frequency << endl;
    cout << "Byte率      ：" << WAV.Bps << endl;
    cout << "样本位数    ：" << WAV.sample_num_bit << endl;
    cout << "音频数据大小：" << WAV.data_size << endl;
    cout << "总计打印行数：" << m << endl;

    delete[] WAV.data;
    int n;
    cout << "出现的数字代表星星的数量，输入任意值结束程序";
    cin >> n;
}