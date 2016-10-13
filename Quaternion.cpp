#include <iostream>
using namespace std;

	class MyQuaternion
	{
	public:
		double Dot(double q1[], double q2[]);
		void MySlerp(double p[], double q1[], double q2[], double t, double rad);
		double Sin(double x);

	};

	double MyQuaternion::Dot(double q1[], double q2[])//��̃N�H�[�^�j�I���̓��ς��v�Z
	{
		return q1[0] * q2[0] + q1[1] * q2[1] + q1[2] * q2[2] + q1[3] * q2[3];
	}
	double MyQuaternion::Sin(double x) {//sin�̒l���v�Z�i�ߎ����ł���colnum�̒l���傫���قǐ��m�j
		double s = 0;
		double r;
		double e;
		const int colnum = 100;
		for (int i = 1; i < colnum; i++) {//sin x = x/1! - x^3/3! + x^5/5! - x^7/7! - �c�̗��p
			r = 1;
			e = 1;
			for (int j = 0; j < 2 * i - 1; j++)
				r *= x;
			for (int j = 0; j < 2 * i - 1; j++)
				e *= 2 * i - 1 - j;
			if (i % 2 == 1) {
				s += r / e;
			}
			else
				s -= r / e;
		}
		return s;
	}

	void MyQuaternion::MySlerp(double p[], double q1[], double q2[], double t, double rad)//q1,q2�̋��ʐ��`��Ԃ�p�Ɋi�[����
	{
		if (Dot(q1, q2) < 0.00) {//���ς����̒l���ƍŒZ�ł͂Ȃ����߃}�C�i�X���|����
			q1[0] = -q1[0];
			q1[1] = -q1[1];
			q1[2] = -q1[2];
			q1[3] = -q1[3];
		}
		p[0] = Sin((1 - t)*rad) / Sin(rad) * q1[0] + Sin(t*rad) / Sin(rad) * q2[0];
		p[1] = Sin((1 - t)*rad) / Sin(rad) * q1[1] + Sin(t*rad) / Sin(rad) * q2[1];
		p[2] = Sin((1 - t)*rad) / Sin(rad) * q1[2] + Sin(t*rad) / Sin(rad) * q2[2];
		p[3] = Sin((1 - t)*rad) / Sin(rad) * q1[3] + Sin(t*rad) / Sin(rad) * q2[3];
	}
	
