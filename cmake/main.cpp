#include<iostream>
#include<Eigen/Dense>
#include"hello.h"
#define M_PI 3.14159265358979323846

using namespace std;

using Eigen::MatrixXd;

Eigen::Vector4d Homo(Eigen::Vector3d p){
    Eigen::Vector4d p1;
    // cout<<p.size()<<endl;
    p1.block<3,1>(0,0)=p;
    p1(3,0)=1;

    return p1;
}

void solution(void){
    Eigen::Quaterniond q1(0.35,0.2,0.3,0.1);
    Eigen::Quaterniond q2(-0.5,0.4,-0.1,0.2);

    Eigen::Vector3d t1(0.3,0.1,0.1);
    Eigen::Vector3d t2(-0.1,0.5,0.3);
    Eigen::Vector3d pc1(0.5,0,0.2);
    Eigen::Vector4d p,pc2;

    cout<<Homo(pc1)<<endl;

    Eigen::Matrix4d Tcw1=Eigen::Matrix4d::Zero();
    Eigen::Matrix4d Twc1=Eigen::Matrix4d::Zero();
    Eigen::Matrix4d Tcw2=Eigen::Matrix4d::Zero();
    Eigen::Matrix4d Twc2=Eigen::Matrix4d::Zero();

    Twc1.block<3,3>(0,0)=q1.matrix();
    Twc1.block<3,1>(0,3)=t1.transpose();    
    Twc1(3,3)=1;

    cout<<"Twc1:\n"<<Twc1<<endl;

    Tcw1=Twc1.inverse();

    cout<<"Tcw1:\n"<<Tcw1<<endl;
    
    Twc2.topLeftCorner(3,3)=q1.matrix();
    Twc2.col(3)=Homo(t2);

    cout<<"Twc2:\n"<<Twc2<<endl;

    Tcw2=Twc2.inverse();

    cout<<"Tcw2:\n"<<Tcw2<<endl;


    p=Twc1*Homo(pc1);

    cout<<"p\n"<<p<<endl;
    cout<<"Pc1(compute)\n"<<Tcw1*p<<endl;
    cout<<"Pc1(origin)\n"<<pc1<<endl;

    pc2=Tcw2*p;

    cout<<"Pc2\n"<<pc2<<endl;

}


int main(void){


    solution();

    return 0;


    cout<<"main"<<endl;

    hello();

    MatrixXd m(2,2);
    m(0,0) = 2;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);


    MatrixXd m_ = m.inverse();
    std::cout << m << std::endl;
    std::cout << m_ << std::endl;

    Eigen::Matrix3d Rotation_Matrix =Eigen::Matrix3d::Identity();

    Eigen::AngleAxisd rotation_vector(M_PI/2,Eigen::Vector3d(0,0,1));


    cout<<"rotaion matrix\n"<<rotation_vector.matrix()<<endl;

    Rotation_Matrix = rotation_vector.matrix();

    Eigen::Vector3d object(1,0,0),obj_;

    obj_=rotation_vector*object;
    cout .precision(3);

    cout<<obj_<<endl;

    obj_=Rotation_Matrix*object;

    cout<<obj_<<endl;


    Eigen::Quaterniond q1(1,1,1,1);
    Eigen::Quaterniond q2(2,2,2,2);
    
    
    double theta=M_PI/2;
    Eigen::Vector3d axis(0,0,1);
    double cos_theta_2=cos(theta/2);
    double sin_theta_2=sin(theta/2);
    Eigen::Quaterniond q3(cos_theta_2,axis[0]*sin_theta_2,axis[1]*sin_theta_2,axis[2]*sin_theta_2);
    cout<<"q3\n"<<q3.matrix()<<endl;
    Eigen::Quaterniond q4(Eigen::AngleAxisd(theta,axis));
    cout<<"q4\n"<<q4.matrix()<<endl;

    Eigen::AngleAxisd r1(q1);
    Eigen::AngleAxisd r2(q2);


    cout<<r1.matrix()<<endl;
    cout<<r2.matrix()<<endl;


    Eigen::Matrix4d T=Eigen::Matrix4d::Zero();

    T.block<3,3>(0,0)=Rotation_Matrix;


    cout<<T<<endl;
    

    return 0;


}