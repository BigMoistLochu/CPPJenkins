pipeline {
    agent any
    stages {
        stage("Checkout") {
            steps {
                git url: 'https://github.com/BigMoistLochu/CPPJenkins', branch: 'main'
            }
        }
        stage("Compile and Build") {
            steps {
                sh '''
                cd AplikacjaCPP
                mkdir -p build
                cd build
                rm -rf *
                cmake ..
                make
                '''
            }
        }
        stage("Unit Test") {
            steps {
                sh '''
                cd AplikacjaCPP/build
                chmod +x runTests
                ./runTests
                '''
            }
        }
        stage('Coverage') {
            steps {
                sh '''
                    cd AplikacjaCPP/build
                    gcov ../src/*.cpp
                '''
            }
        }
        stage('Static Analysis') {
            steps {
                sh '''
                    cd AplikacjaCPP
                    cppcheck --enable=all --inconclusive --xml --xml-version=2 src 2> build/cppcheck-report.xml
                '''
            }
            post {
                always {
                    // Publikacja raportu z cppcheck
                    publishHTML(target: [
                        allowMissing: false,
                        alwaysLinkToLastBuild: true,
                        keepAll: true,
                        reportDir: 'AplikacjaCPP/build',
                        reportFiles: 'cppcheck-report.xml',
                        reportName: 'Cppcheck Report'
                    ])
                }
            }
        }
    }
}
