FROM jenkins/jenkins:lts

USER root

# Zaktualizuj listę pakietów i zainstaluj narzędzia do kompilacji C++
RUN apt-get update && \
    apt-get install -y build-essential && \
    apt-get install -y cmake

USER jenkins

EXPOSE 8080

# CMD to run Jenkins
CMD ["jenkins.sh"]
